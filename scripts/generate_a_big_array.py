import random

print("generating 10 million random numbers...")
array = [random.randint(1, 255) for _ in range(1_000_000)]

header_filename = "src/generated_array.h"
print(f"Writing to {header_filename}...")

with open(header_filename, 'w') as f:
    f.write("#ifndef GENERATED_ARRAY_H\n")
    f.write("#define GENERATED_ARRAY_H\n\n")
    f.write("#include <stdint.h>\n\n")
    f.write(f"#define ARRAY_SIZE {len(array)}\n\n")
    f.write("extern uint8_t generated_array[ARRAY_SIZE];\n\n")
    f.write("#endif // GENERATED_ARRAY_H\n")

program_filename = "src/generated_array.c"
print(f"Writing to {program_filename}...")


with open(program_filename, 'w') as f:
    f.write("#include \"generated_array.h\"\n\n")
    f.write("uint8_t generated_array[ARRAY_SIZE] = {\n")

    for i in range(0, len(array), 10):
        line_elements = array[i:i+10]
        f.write("    " + ", ".join(map(str, line_elements)))
        if i + 10 < len(array):
            f.write(",\n")
        else:
            f.write("\n")

    f.write("};\n\n")


print(f"successfully wrote {len(array)} elements to {header_filename}")