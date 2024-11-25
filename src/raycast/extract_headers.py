import re
import os

def extract_function_declarations(file_path):
    """Extract function declarations from a single file."""
    # Regex to match function declarations while excluding unwanted patterns
    function_pattern = re.compile(
        r"^\s*(?!static|if|else\s*if|else|while|for|main|break|exit)"
        r"[a-zA-Z_][a-zA-Z0-9_]*\s+\**[a-zA-Z_][a-zA-Z0-9_]*\s*\([^)]*\)\s*",
        re.MULTILINE | re.DOTALL
    )
    try:
        with open(file_path, 'r') as file:
            content = file.read()  # Read the entire file content
            
        # Find all matches of function declarations
        matches = function_pattern.findall(content)
        
        # Strip any trailing curly brackets and add a semicolon
        cleaned_matches = [match.strip() + ";" for match in matches]
        
        return cleaned_matches
    
    except FileNotFoundError:
        print(f"File not found: {file_path}")
    except Exception as e:
        print(f"An error occurred while processing {file_path}: {e}")
        return []

def process_c_files_in_directory(base_path):
    """Process all `.c` files in the current directory and its subdirectories."""
    function_declarations = []
    
    for root, _, files in os.walk(base_path):
        for file in files:
            if file.endswith(".c"):
                file_path = os.path.join(root, file)
                print(f"Processing file: {file_path}")
                function_declarations.append("//functions from " + file_path)
                declarations = extract_function_declarations(file_path)
                if declarations:
                    function_declarations.extend(declarations)  # Add declarations to the main list
                else:
                    function_declarations.pop()
    
    return function_declarations

def filter_out_main_lines(results):
    """Filter out lines that contain 'main' unless they start with '//'."""
    return [line for line in results if "main" not in line or line.lstrip().startswith("//")]

if __name__ == "__main__":
    base_path = input("Enter the path to the directory (or '.' for the current directory): ")
    start_folder = os.getcwd()  # Current working directory
    output_file_path = os.path.join(start_folder, "extracted_functions.h")

    results = process_c_files_in_directory(base_path)
    
    # Filter out unwanted lines
    results = filter_out_main_lines(results)
    
    if results:
        # Write results to "extracted_functions.h"
        try:
            with open(output_file_path, 'w') as output_file:
                output_file.write("// Extracted Function Declarations\n")
                output_file.write("// This file was generated automatically.\n\n")
                for func in results:
                    output_file.write(func + "\n")
            print(f"\nFunction declarations saved to {output_file_path}")
        except Exception as e:
            print(f"An error occurred while writing to the file: {e}")
    else:
        print("No function declarations found.")
