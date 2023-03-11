#include <iostream>
#include <vector>


  std::vector<int> vec(num);
  for (int i=0; i<num; i++) {
    std::cout << "Enter #" << i+1 << " number: ";
    std::cin >> vec[i];
  }
  
  for (int i=num-1; i>=0; i--) {
    std::cout << vec[i] << std::endl;
  }

  

}