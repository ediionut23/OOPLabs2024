#pragma once

template <typename K, typename V>
class MapItem{
public:
    int index;
    K key;
    V value;
};

template<typename K, typename V>
class Map {
private:
    MapItem<K,V> items[50];
    int count = 0 ;
public:
    int Count(){
        return count;
    }

    void Set(K key, V value){
        for(int i = 0; i < count; i++){
            if(items[i].key == key){
                items[i].value = value;
                return;
            }
        }
        items[count] = {count,key,value};
        ++count;
    }

    bool Get(K key, V value){
        for(int i = 0; i < count; i++)
            if(items[i].key == key) {
                value = items[i].value;
                return true;
            }
        return false;
    }

    void Clear(){
        count = 0;
    }

    bool Delete(K key){
        for(int i = 0; i < count; i++)
            if(items[i].key == key) {
                for (int j = i + i; j < count; j++)
                    items[j - 1] = items[j];
                return true;
            }
        return false;
    }

    bool Includes(Map<K,V> map){
        if(map.count > count)
            return false;
        for(int i = 0; i < map.count; i++){
            bool ok = false;
            for(int j = 0; j < count; j++){
                if(map.items[i].key == items[j].key){
                    ok = true;
                    break;
                }
            }
            if(!ok)
                return false;
        }
        return true;
    }

    V& operator[](K key){
        for(int i = 0 ; i < count ;i++)
            if(items[i].key == key){
                return items[i].value;
            }

        items[count] = {count,key,V()};
        ++count;
        return items[count-1].value;
    }

    bool operator!=(Map<K, V>& map) {
        if (count != map.count)
            return true;
        for (int i = 0; i < count; i++) {
            if (items[i].key != map.items[i].key)
                return true;
            if (items[i].value != map.items[i].value)
                return true;
        }
        return false;

    }
    auto begin(){
        return &items[0];
    }
    auto end(){
        return &items[count];
    }
};