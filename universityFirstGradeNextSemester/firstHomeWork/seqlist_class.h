class Seqlist
{
private:
    Type *data;
    int size;
    int max;
public:
    Seqlist(int n=100);
    ~SeqList();
    // 修改函数成员
    void InsertRear(const Type& item);
    void Insert(int id,const Type& item);
    void Erase(int id);
    void Clear();
    // 用于读取的成员函数
    void Type& Getdata
}
