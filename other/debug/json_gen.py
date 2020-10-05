# This python script aims at generating multi-line json string content from a file.
# The generated multi-line json string content can be used in the User Snippet of the Visual Studio Code 

in_file_name = input("Input file name: ")
in_file = open(in_file_name, 'r')
in_file_content = in_file.read().split('\n')
in_file.close()

for i in range(0, len(in_file_content)):
    line = in_file_content[i].replace("\"", "\\\"")
    print("\"" + line + "\"", end="")
    if i != len(in_file_content) - 1:
        print(",")
    else:
        print()
