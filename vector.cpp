//Vector
    #include <vector>
    ...
    std::vector<int> v;
//The vector has size 0 when we instantiate it.
    v.size()
    v.resize(4)

//Iterators:
    std::vector<int> v;
    std::vector<int>::iterator it; 
    ...
    for(it=v.begin(); it!=v.end(); it++)
        std::cout<<*it<<" ";//We dereference the iterator to print out the value of the vector

    v.assign(4,3); //assign the value 3 to 4 elements of the vector
    //3 3 3 3

    //NB: the iterator must be create in the function where it is used
    
    void printVector(vector<float> vIn){
        vector<float>::iterator it;
        for(it=vIn.begin(); it!=vIn.end(); it++)
            cout<<*it<<" ";
    }

//Add Elements:
    v.assign(quanti elementi a partire dal primo, cosa metterci)
        v.assign(1,23) //-> 23
        v.assign(10,2) //-> 2 2 2 2 2 2 2 2 2 2
    
    //Limit: 23 is written over with a 3
    //::assign writes over the elements in the vector

    v.push_back(elemento da aggiungere alla fine del vector)
        v.push_back(24) //-> 2 2 2 2 2 2 2 2 2 2 24 

    //::push_back modifies also the size automatically

    v.insert(iterator settato, valore)
    //Before we insert, we need to set the iterator to a known destination. 
    //In this case we set it to the beginning of the vector plus one
        it=v.begin()+1;
        v.insert(it,-1);

        it=v.begin();
        v.insert(it+3,-2)
    //Ogni volta che si vuole aggiungere con insert è necessario resettare l'iterator
    //es:
        //constructing vectors
        #include <iostream>
        #include <vector>

        int main ()
        {
        //creating a vector of integers
        std::vector<int> vectorInts;  
        //creating an iterator for the vector
        std::vector<int>::iterator it;

        vectorInts.push_back(0);
        vectorInts.push_back(1);
        vectorInts.push_back(2);
        vectorInts.push_back(3);
        vectorInts.push_back(4);
        vectorInts.push_back(5);
        vectorInts.push_back(6);
        vectorInts.push_back(7);
        
        std::cout<<"vectorInts has "<<vectorInts.size()<<" elements\n";
        
        //printing the contents of vectorInts
        std::cout<<"VectorInts has these elements:\n";
        for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
            std::cout<<*it<<" ";
        
        //insert an element after the first element
        it  = vectorInts.begin() + 1;
        vectorInts.insert(it, -1);
        std::cout<<"\n\nAfter the insert\n";
        for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
            std::cout<<*it<<" ";
            
        //insert an element after the third element
        it  = vectorInts.begin();
        vectorInts.insert(it + 3, -2);
        std::cout<<"\n\nAfter the insert\n";
        for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
            std::cout<<*it<<" ";

        //insert an element after the third element
        it  = vectorInts.begin();
        vectorInts.insert(it + 5, -3);
        std::cout<<"\n\nAfter the insert\n";
        for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
            std::cout<<*it<<" ";
            
        return 0;
        }
    /*
    Output: 
        vectorInts has 8 elements
        VectorInts has these elements: 0 1 2 3 4 5 6 7
        After the insert: 0 -1 1 2 3 4 5 6 7
        After the insert: 0 -1 1 -2 2 -3 3 4 5 6 7
    */
    
    v.emplace() 
    //Emplace puts an element in a vector at the position pointed to by the iterator
    //Emplace differs from insert in the method used to insert the elemnt.
    //Insert COPIES the values of the vector while emplace does an IN-PLACE INSERTION.
    //This means the insertion occurs at the point after the iterator.
        it  = v.begin() + 1;
        v.emplace(it, -1);
    //A livello pratico non ho trovato molta differenza (emplace.cpp)

    //es with add-elements methods-> add.cpp

//Erase elements
    v.clear()
    //Clear all the elements in the vector v (See already in the add.cpp)

    v.erase(elimina un singolo elemento o un range di elementi)
        v.erase(v.begin()+4); //elimina il V
        v.erase(v.begin()+1, v.begin()+3); //elimina dal II al IV
    
    v.pop_back()
    //Delete the last element of a vector
    //Note: ::pop_back DOES NOT return a value
        //int a;
        //a=v.pop_back() //This line does not compile
    


    




    
    

    

