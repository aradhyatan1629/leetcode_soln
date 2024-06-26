class ParkingSystem {
public:
    int b=0,m=0,s=0;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 and b>0)
        {
            b--;
            return true;
        }
        else if(carType==2 and m>0)
        {
            m--;
            return true;
        }
        else if(carType==3 and s>0)
        {
            s--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */