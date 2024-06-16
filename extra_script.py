Import("env")
import os

# List installed packages
env.Execute("$PYTHONEXE -m pip list")

# Install custom packages from the PyPi registry
env.Execute("$PYTHONEXE -m pip install Pillow Numpy")

# Install missed package
try:
    from PIL import Image
    import numpy as np
except ImportError:
    env.Execute("$PYTHONEXE -m pip install pillow numpy")

# Get the project directory from the environment
project_dir = env['PROJECT_DIR']

# Run the generate_bitmaps.py script located in the same directory as this script
generate_bitmaps_script = os.path.join(project_dir, "generate_bitmaps.py")
env.Execute(f"$PYTHONEXE {generate_bitmaps_script}")