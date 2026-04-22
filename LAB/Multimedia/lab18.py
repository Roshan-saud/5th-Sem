# Write a program to implement Huffman Coding for
# compression. Write a program to implement run
# length encoding using any high-level programming
# (c#, C++, python).

# Program to implement Huffman Coding and Run Length Encoding

import heapq
from collections import Counter


# ---------- Huffman Coding ----------
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_tree(text):
    frequency = Counter(text)
    heap = []

    for char, freq in frequency.items():
        heapq.heappush(heap, Node(char, freq))

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(heap, merged)

    return heap[0]


def generate_codes(node, code="", codes={}):
    if node is None:
        return

    if node.char is not None:
        codes[node.char] = code

    generate_codes(node.left, code + "0", codes)
    generate_codes(node.right, code + "1", codes)

    return codes


def huffman_encoding(text):
    tree = build_tree(text)
    codes = generate_codes(tree)

    print("\nHuffman Codes:")
    for char, code in codes.items():
        print(char, ":", code)

    encoded = ''.join(codes[c] for c in text)

    print("Encoded Text:", encoded)


# ---------- Run Length Encoding ----------
def run_length_encoding(data):
    encoding = ""
    i = 0

    while i < len(data):
        count = 1

        while i + 1 < len(data) and data[i] == data[i + 1]:
            i += 1
            count += 1

        encoding += data[i] + str(count)
        i += 1

    return encoding

 
# ---------- Main Menu ----------
print("Compression Techniques")
print("1. Huffman Coding")
print("2. Run Length Encoding")

choice = int(input("Enter your choice: "))
text = input("Enter the text: ")

if choice == 1:
    huffman_encoding(text)

elif choice == 2:
    compressed = run_length_encoding(text)
    print("Compressed Text:", compressed)

else:
    print("Invalid Choice")