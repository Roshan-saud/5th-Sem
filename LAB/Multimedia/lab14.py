#  WAP to covert image into black and white using
# any high-level programming (c#, C++, python).

from PIL import Image
# Open the image
img = Image.open("nature.jpg")
# Convert to grayscale
gray = img.convert("L")
# Convert to Black & White using threshold
bw = gray.point(lambda x: 255 if x > 128 else 0, '1')
# Save output image
bw.save("black_white.jpg")
print("Image converted to Black & White successfully")
 