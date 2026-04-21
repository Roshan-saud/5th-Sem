# WAP to compress the image using any high-level
# programming (c#, C++, python).

from PIL import Image

# Open the image
img = Image.open("nature.jpg")

# Compress and save image
img.save("compressed.jpg", optimize=True, quality=20)

print("Image compressed successfully")                                                                                          
 