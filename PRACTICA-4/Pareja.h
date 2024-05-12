#ifndef PRACTICA_4_PAREJA_H
#define PRACTICA_4_PAREJA_H

template<typename T, typename K>
class Pareja {

public:
    Pareja(const T &var1, const K &var2);

    T getVar1() const;
    void setVar1(T var1);

    K getVar2() const;
    void setVar2(K var2);

private:

    T var1;
    K var2;

};
template<typename T, typename K>
T Pareja<T, K>::getVar1() const {
    return var1;
}

template<typename T, typename K>
void Pareja<T, K>::setVar1(T var1) {
    Pareja::var1 = var1;
}

template<typename T, typename K>
K Pareja<T, K>::getVar2() const {
    return var2;
}

template<typename T, typename K>
void Pareja<T, K>::setVar2(K var2) {
    Pareja::var2 = var2;
}

template<typename T, typename K>
Pareja<T, K>::Pareja(const T &var1, const K &var2) {

    this -> var1 = var1;
    this -> var2 = var2;
}



#endif //PRACTICA_4_PAREJA_H
