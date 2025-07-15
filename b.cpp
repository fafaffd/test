//
//  b.cpp
//  
//
//  Created by 郭天宇 on 2025/7/15.
//

#include <string>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> a(10,1);
    for(auto i : a){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
    return 0;
}
