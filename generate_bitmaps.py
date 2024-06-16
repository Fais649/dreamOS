import os
from PIL import Image
import numpy as np
def convert_image_to_bitmap(image_path):
    # Open the image file
    img = Image.open(image_path)
    
    # Get the image dimensions
    width, height = img.size
    
    # Convert image to grayscale
    grayscale_img = img.convert('L')
    
    # Convert image to binary (black and white)
    binary_img = grayscale_img.point(lambda x: 0 if x < 128 else 1, '1')
    
    # Convert image to numpy array
    bitmap_array = np.array(binary_img)
    
    # Flatten the 2D array to 1D
    bitmap_1d = bitmap_array.flatten()
    
    return bitmap_1d

def print_bitmap(bitmap, width):
    for i in range(0, len(bitmap), width):
        line = bitmap[i:i + width]
        print("".join(['#' if pixel else ' ' for pixel in line]))

def generate_cpp_header_files(image_path, root_dir):
    image_name = os.path.splitext(os.path.basename(image_path))[0]
    camel_case_name = ''.join(word.title() for word in image_name.split('_'))
    relative_path = os.path.relpath(image_path, os.path.join(root_dir, 'image'))
    include_path = os.path.join(root_dir, 'include', 'bitmap', os.path.dirname(relative_path))
    src_path = os.path.join(root_dir, 'src', 'bitmap', os.path.dirname(relative_path))

    os.makedirs(include_path, exist_ok=True)
    os.makedirs(src_path, exist_ok=True)

    bitmap = convert_image_to_bitmap(image_path)
    bitmap_cpp_array = ', '.join(map(str, bitmap.astype(int)))

    header_content = f"""#ifndef {camel_case_name.upper()}_H
#define {camel_case_name.upper()}_H

#include <stdint.h>

const uint8_t {camel_case_name}[] = {{{bitmap_cpp_array}}};

#endif
"""

    cpp_content = f"""#include "bitmap/{os.path.relpath(os.path.join(include_path, camel_case_name + '.h'), src_path).replace(os.sep, '/')}"

// The bitmap array and dimensions are defined in the header file.
"""

    header_file_path = os.path.join(include_path, camel_case_name + '.h')
    cpp_file_path = os.path.join(src_path, camel_case_name + '.cpp')

    with open(header_file_path, 'w') as header_file:
        header_file.write(header_content)

    with open(cpp_file_path, 'w') as cpp_file:
        cpp_file.write(cpp_content)

def process_images(root_dir):
    image_dir = os.path.join(root_dir, 'image')
    for root, _, files in os.walk(image_dir):
        for file in files:
            if file.endswith(('png', 'jpg', 'jpeg', 'bmp')):
                image_path = os.path.join(root, file)
                generate_cpp_header_files(image_path, root_dir)

root_directory = '.'  # Root directory of the project

process_images(root_directory)