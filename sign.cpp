#include <iostream>
#include <filesystem>
#include <unistd.h>

bool sign_efi_files(std::filesystem::path &dir){
    bool errors = false;
    for(const auto &entry : std::filesystem::recursive_directory_iterator(dir))
    {
        if(entry.is_regular_file() && entry.path().extension() == ".efi" || 
        entry.path().extension() == ".mui" || entry.path().extension() == ".dll")
        {
            std::string command = "sbctl sign " + entry.path().string();
            std::cout << "Signing: " << entry.path() << std::endl;
            int result = std::system(command.c_str());
            if(result != 0)
            {
                std::cerr << "Error signing " << entry.path() << std::endl;
                errors = true;
            }
        }
    }
    return errors;
}

int main(int argc, char* arg_arr[])
{
    if(geteuid() !=0)
    {
        std::cout << "\nPlease call the program with root previleges.\n" << std::endl;
        return 1;
    }
    if(argc != 2)
    {
        std::cout << "Invalid argument numbers." << std::endl;
        return -1;
    }
    std::filesystem::path path = std::filesystem::path(arg_arr[1]);
    bool result = sign_efi_files(path);
    if(result)
    {
        std::cout << "\nSigning completed without errors." << std::endl;
    }
    else{
        std::cout << "\nSigning completed with errors." << std::endl;
        return -1;
    }
    return 0;
}