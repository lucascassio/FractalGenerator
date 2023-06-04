def count_symbols(string):
    count_f = string.count('F')
    count_total = len(string)
    return count_f, count_total


def main():
    filename = "fractal.txt"

    with open(filename, "r") as file:
        content = file.read()

    iterations = content.count("Iteração")
    start_index = 0

    for i in range(iterations):
        iteration_index = content.find("Iteração", start_index + 1)
        if iteration_index == -1:
            iteration_index = len(content)
        
        iteration_content = content[start_index:iteration_index]
        start_index = iteration_index

        lines = iteration_content.strip().split("\n")
        iteration_number = int(lines[0].split()[1][:-1])
        current_string = lines[1]

        count_f, count_total = count_symbols(current_string)
        print(f"Iteração {iteration_number}:")
        print(f"Quantidade de símbolos 'F': {count_f}")
        print(f"Quantidade total de símbolos: {count_total}")
        print()

if __name__ == "__main__":
    main()

