# WAP to covert image into gray scale using any
# high-level programming (c#, C++, python).

# WAP to convert image into grayscale using Python
from PIL import Image

# open image
img = Image.open("nature.jpg")

# convert to grayscale
gray_img = img.convert("L")

# save new image
gray_img.save("gray_image.jpg")

print("Image converted to grayscale successfully!") 