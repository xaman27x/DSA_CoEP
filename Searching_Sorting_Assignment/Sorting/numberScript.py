import random

num_values = 50000
random_numbers = [random.randint(1, 1000000) for _ in range(num_values)]

output_file_path = 'random_integers_50000.csv'

with open(output_file_path, 'w') as file:
    for index, value in enumerate(random_numbers):
        file.write(f"{index},{value}\n")

print(f"File saved as {output_file_path}")
