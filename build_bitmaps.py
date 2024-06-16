import os
import re
from PIL import Image

def convert_to_camel_case(snake_str):
    components = re.split('_|-|\\.', snake_str)
    return ''.join(x.title() for x in components)

def convert_image_to_bitmap(image_path, output_cpp, output_header, const_name):
    print(f"Processing image: {image_path}")
    img = Image.open(image_path).convert('L')
    width, height = img.size
    pixels = img.load()

    bitmap = []

    for y in range(height):
        for x in range(width):
            color = 0x00 if pixels[x, y] == 255 else 0xFF
            bitmap.append(color)

    with open(output_cpp, 'w') as f:
        base_name = os.path.basename(output_cpp).replace('.cpp', '')
        f.write(f'#include "{base_name}.h"\n\n')
        f.write(f'const uint8_t {const_name}[] = {{\n')
        for i in range(0, len(bitmap), 12):
            line = ', '.join(f'0x{bitmap[j]:02X}' for j in range(i, min(i + 12, len(bitmap))))
            f.write(f'    {line},\n')
        f.write('};\n')

    with open(output_header, 'w') as f:
        include_guard = f'{const_name.upper()}_H'
        f.write(f'#ifndef {include_guard}\n')
        f.write(f'#define {include_guard}\n\n')
        f.write('#include <stdint.h>\n\n')
        f.write(f'extern const uint8_t {const_name}[];\n')
        f.write(f'const int {const_name}_WIDTH = {width};\n')
        f.write(f'const int {const_name}_HEIGHT = {height};\n')
        f.write(f'#endif // {include_guard}\n')

def create_bitmap_files(src_dir, dest_dir):
    for root, _, files in os.walk(src_dir):
        for file in files:
            if file.endswith('.png'):
                relative_path = os.path.relpath(root, src_dir)
                base_name = os.path.splitext(file)[0]
                camel_case_name = convert_to_camel_case(base_name)
                cpp_dir = os.path.join(dest_dir, relative_path)
                os.makedirs(cpp_dir, exist_ok=True)

                cpp_file = os.path.join(cpp_dir, f'{camel_case_name}Bitmap.cpp')
                header_file = os.path.join(cpp_dir, f'{camel_case_name}Bitmap.h')

                convert_image_to_bitmap(os.path.join(root, file), cpp_file, header_file, f'{camel_case_name}Bitmap')

def main():
    images_dir = os.path.join(os.path.dirname(__file__), 'image')
    headers_dir = os.path.join(os.path.dirname(__file__), 'include', 'bitmap')
    os.makedirs(headers_dir, exist_ok=True)

    create_bitmap_files(images_dir, headers_dir)
    print("Bitmap files created successfully")

if __name__ == "__main__":
    main()