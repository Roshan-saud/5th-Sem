# WAP to generate a sound using any high-level
# programming (c#, C++, python).

import winsound

# Generate sound
frequency = 1000   # Frequency in Hertz
duration = 1000    # Duration in milliseconds

winsound.Beep(frequency, duration)

print("Sound generated successfully")
 