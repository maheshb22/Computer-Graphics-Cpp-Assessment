#include <iostream>
#include <cstring>

class StringArray
{
private:
    char** data;
    size_t size;

public:

    StringArray(size_t n)
    {
        size = n;
        data = new char*[size];

        for(size_t i=0;i<size;i++)
        {
            data[i] = new char[1];
            data[i][0]='\0';
        }
    }

    void setString(size_t index,const char* str)
    {
        if(index>=size)
            return;

        delete[] data[index];

        if(str==nullptr)
        {
            data[index]=new char[1];
            data[index][0]='\0';
            return;
        }

        data[index]=new char[strlen(str)+1];
        strcpy(data[index],str);
    }

    const char* getString(size_t index) const
    {
        if(index>=size)
            return nullptr;

        return data[index];
    }

    ~StringArray()
    {
        for(size_t i=0;i<size;i++)
            delete[] data[i];

        delete[] data;
    }
};

/*From the above code written 
a)
In order to no memory leak the destructor using delete[] deletes the every individual character array and then frees the pointer associated with it which ensures the no memory leaks

b)
if null pointer is passed to setString it leads to crashes, the code handles it by creating an empty string (null terminator only) for that index. 

c)
If we write StringArray b=a it will create an shalow copy that share the same pointer leading to undefined behaviour this can be avoided by proper copy constructor and copy assignment operator*/
