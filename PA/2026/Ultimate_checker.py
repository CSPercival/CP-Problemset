import subprocess
import filecmp
from colorama import Fore, Style
import os
import time

def print_file (path):
    try:
        with open(path, 'r') as file:
            for line in file:
                print(line, end='')  # 'end=''` prevents extra newline characters
    except FileNotFoundError:
        print(f"The file {path} does not exist.")
    except IOError as e:
        print(f"An error occurred while reading the file: {e}")

def remove_carriage_returns(filename):
    with open(filename, 'r', newline='') as f:
        content = f.read().replace('\r', '')  # Remove all \r

    with open(filename, 'w', newline='') as f:
        f.write(content)

checker_parameters = "checker_parameters.txt"

if os.path.exists(checker_parameters):
    try:
        with open(checker_parameters, 'r') as file:
            parameters = [line.strip() for line in file.readlines()]
            cpp_program = parameters[0]
            test_path = parameters[1]
            number_of_tests = int(parameters[2])
            prefix = ""
            if(len(parameters) >= 4):
                prefix = parameters[3]

    except IOError as e:
        print(f"An error occurred while reading the file: {e}")
else:
    cpp_program = input("Enter cpp program name: ")
    test_path = input("Enter test path: ")
    number_of_tests = int(input("Enter number of test: "))
    prefix = input("Enter prefix of each test: ")
    
    with open(checker_parameters, 'w') as file:
        file.write(cpp_program)
        file.write('\n')
        file.write(test_path)
        file.write('\n')
        file.write(str(number_of_tests))
        file.write('\n')
        file.write(prefix)



wzo_output = test_path + "/wzo_out.txt"

# print(cpp_program, "XD",test_path)
if len(cpp_program) < 4 or cpp_program[-4:] != ".cpp":
    cpp_program += ".cpp"
# print(cpp_program)

compile_command = ["g++", cpp_program, "-o", "wzo_prog","-O2"] 
run_command = ["./wzo_prog"] 
 
compile_process = subprocess.run(compile_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE) 
 
if compile_process.returncode == 0: 
    print("Compilation successful.") 
    for i in range(1,number_of_tests + 1):
        in_file = test_path + "/" + prefix + str(i) + ".in"
        out_file = test_path + "/" + prefix + str(i) + ".out"

        if(os.path.exists(in_file) == False):
            print(i,':',f"{Fore.MAGENTA}IN FILE MISSING{Style.RESET_ALL}", in_file)
            continue

        if(os.path.exists(in_file) == False):
            print(i,':',f"{Fore.MAGENTA}OUT FILE MISSING{Style.RESET_ALL}", out_file)
            continue

        remove_carriage_returns(in_file)
        remove_carriage_returns(out_file)

        start_time = time.time()
        with open(in_file, "r") as input_file, open(wzo_output,"w") as output_file:
            run_process = subprocess.run(run_command, stdin=input_file, stdout=output_file, stderr=subprocess.PIPE)
        end_time = time.time()
        elapsed_time = end_time - start_time

        remove_carriage_returns(wzo_output)

        are_files_equal = filecmp.cmp(out_file, wzo_output)
        if are_files_equal:
            if elapsed_time > 5:
                print(i,':',f"{Fore.YELLOW}TLE{Style.RESET_ALL}",elapsed_time)
                # continue
                break
            print(i,':',f"{Fore.GREEN}Accepted{Style.RESET_ALL}",elapsed_time)
        else:
            print(i,':',f"{Fore.RED}Wrong Answer{Style.RESET_ALL}",elapsed_time)
            
            print(f"{Fore.YELLOW}")
            print("Program:", cpp_program)
            print("INPUT FILE:", in_file)
            print("OUTPUT FILES:",out_file,wzo_output)
            print(f"{Style.RESET_ALL}")

            # with open(checker_parameters, 'w') as file:
            #     file.write(cpp_program)
            #     file.write('\n')
            #     file.write(test_path)
            #     file.write('\n')
            #     file.write(str(number_of_tests))
            #     file.write('\n')
            #     file.write(prefix)

            # print_file(out_file)
            # print("VS")
            # print_file(wzo_output)
            
            tmp = input("Enter to continue: ")
            # break
    # error = run_process.stderr.decode() 
    # print("Error:") 
    # print(error) 
else: 
    print("Compilation failed.") 
    print(compile_process.stderr.decode()) 