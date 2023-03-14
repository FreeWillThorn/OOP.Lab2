
class Track{

private:
    string Title;
    int Length;

public:
    Track(){
        this->Length = 0;
    };
    Track(const string& Title, const int& Length)//l-value reference
    {
        this->Title = Title;
        this->Length = Length;
    }
    
    Track(string&& Title, int&& Length)//r-value reference
    {
        this->Title = move(Title);
        this->Length = Length;
    }

    Track(const Track & other) // copy constructor
    {
        this->Title = other.Title;
        this->Length = other.Length;
    }
    
    Track(Track && other) //Moving constructor
    {
        this->Title = move(other.Title);
        this->Length = move(other.Length);
    }
    
    Track& operator= (const Track& other)// copy assignment
    {
        this->Title = other.Title;
        this->Length = other.Length;
        
        return *this;
    }
    
    Track& operator= (Track&& other)//Move assignment operator
    {
        this->Title = move(other.Title);
        this->Length = move(other.Length);
        return *this;
    }
    
    const string& GetTitle() const
    {
        return Title;
    }
    
    const int& GetLength() const
    {
        return Length;
    }
    
    void SetTitle(const string& Title)//setter with const
    {
        this->Title = Title;
    }
    
    void SetLength(const int& Length)//setter with const
    {
        this->Length = Length;
    }
    
    
    void SetTitle(string&& Title)//setter with r-reference
    {
        this->Title = move(Title);
    }
    
    
    void SetLength(int&& Length)//setter with r-reference
    {
        this->Length = move(Length);
    }
    
};

ostream& operator<<(ostream& out,const Track &track)//std::ostream print operator <<.
{
    
    return out << track.GetTitle() << " - " << track.GetLength();
}

int main(int argc, char **argv)
{
    string t = "Way down we go";
    int a = 20;
    Track e;
    cout << "e: " << e << endl;
    Track b1 = { t, a };
    cout << "b1: " << b1 << endl;
    Track b2 = { "Horseride", 10 };
    cout << "b2: " << b2 << endl;
    Track b3 = b1;
    cout << "b3: " << b3 << " b1: " << b1 << endl;
    e = std::move(b2); // e stole b
    cout << "e: " << e << " b2: " << b2 << endl;
    e.SetTitle("SUGER");
    cout << "e: " << e << endl;
    e.SetLength(5);
    cout << "e: " << e << endl;

    return 0;
}
