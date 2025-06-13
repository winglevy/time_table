#include <iostream>
#include <string>
#include <map>

double str_time(std::string str)
{
    double time = 0;
    
    size_t index = str.find('h');
    
    if(index == std::string::npos) time = std::stoi(str);
    else
    {
        time += std::stoi(str.substr(0, index) ) * 60;
        if(! str.substr(index+1).empty() ) 
            time += std::stoi(str.substr(index + 1) );
    }
    
    return time;
}

int main()
{
    std::string line;
    std::map<char, double> time_table;
    
    
    while(std::getline(std::cin, line) )
    {
        if(line[0] == 'A' || line[0] == 'B' || line[0] == 'D') 
        {
            size_t tmp_i = line.find("--");
            if(tmp_i != std::string::npos)
            {
                if(time_table.find(line[0]) == time_table.end() ) 
                    time_table[line[0] ] = str_time(line.substr(tmp_i + 2));
                else 
                    time_table[line[0] ] += str_time(line.substr(tmp_i + 2));
            }
        }
        if(line[0] == 'q') break;
    }
    
    
    std::cout << "TIME TABLE : \n";
    for(auto it : time_table) std::cout << it.first << " : " << it.second << '\n';
    
    double total = 0;
    for(auto it : time_table) total += it.second;
    std::cout << "total : " << total << '\n';
    
    std::cout << "A / total = " << double(time_table['A']) / total << '\n' ;
    std::cout << "D / total = " << double(time_table['D']) / total << '\n' ;
    
    return 0;
}
