#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>

template <typename T>
class DLLoader {
    public :
        void open(std::string file)
        {
            handler = dlopen(file.c_str(), RTLD_LAZY);
            if (handler == NULL) {
                std::cerr << "dlopen : "<< dlerror() << std::endl;
                exit(84);
            }
        }
        
        void close()
        {
            if (dlclose(handler) == 0) {
                std::cerr << "dlclose : "<< dlerror() << std::endl;
                exit(84);
            }
        }
        
        T *getInstance (std::string funcName) const {
            T *(*fnc)(void) = reinterpret_cast<T *(*)(void)>(dlsym(handler, funcName.c_str()));
            if (fnc == NULL) {
                std::cerr << "dlsym : "<< dlerror() << std::endl;
                exit(84);
            }
            return fnc();
        }

    private:
        void *handler;
};

#endif