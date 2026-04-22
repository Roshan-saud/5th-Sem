# Write a program to calculate the file size in bytes
# for a 30 sec recording at 44.1 khz, 8 bits resolution
# stereo sound using any high-level programming
# (c#, C++, python).
# Given values
sample_rate = 44100        # in Hz
bit_depth = 8              # bits per sample
channels = 2               # stereo
duration = 30              # seconds

# Calculate file size in bytes
file_size_bytes = sample_rate * bit_depth * channels * duration // 8

print("File size:", file_size_bytes, "bytes")
 