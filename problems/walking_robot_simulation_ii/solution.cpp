class Robot {
public:
    Robot(int width, int height)
        : w {width}, h {height}, peri {width * 2 + (height - 2) * 2}
    {}
    
    void step(int num) {
        initialPos = false;
        pos += num;
        pos %= peri;
    }
    
    vector<int> getPos() {
        int bot = w;
        int right = w + h - 1;
        int top = 2 * w + h - 2;
        if (pos < bot)
            return {pos, 0};
        else if (pos < right)
            return {w - 1, pos - bot + 1};
        else if (pos < top)
            return {w - (pos - right + 2), h - 1};
        else
            return {0, h - (pos - top + 2)};
    }
    
    string getDir() {
        if (initialPos)
            return "East";
        if (pos == 0)
            return "South";
        if (pos < w && pos > 0)
            return "East";
        else if (pos < w + h - 1)
            return "North";
        else if (pos < 2 * w + h - 2)
            return "West";
        else
            return "South";
    }
    
private:
    const int w, h;
    const int peri;
    int pos = 0;
    bool initialPos = true;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */