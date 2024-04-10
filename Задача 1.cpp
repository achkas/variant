// Задача 1.

#include "map"
#include "vector"
#include "chrono"
#include "iostream"

struct Query {
    std::string name;
    std::string from;
    std::string where;
    std::vector<std::string> query_V{ "SELECT " };
    std::string all{ "*...; " };
    std::string and_{ "AND " };
    std::string end_Query{ ";" };
    int w_call{ 0 };
    
};



class QueryBuilder {
public:


    Query Buildquery() noexcept
    {
        if (event.name.empty())
        {
            event.query_V.push_back(event.all);
            return event;
        }
        event.query_V.push_back(event.name);
        event.query_V.push_back(event.from);
        event.query_V.push_back(event.where);
        event.query_V.push_back(event.end_Query);       
        return event;
    }

    QueryBuilder& AddColumn(std::string column) noexcept {
        event.name = column + " ";               
        return *this;
    }

    QueryBuilder& AddFrom(std::string column) noexcept {
        event.from = "FROM " + column + " ";             
        return *this;
    }

    QueryBuilder& AddWhere(std::string id, std::string num) noexcept
    {
        if (event.w_call == 0)
        {
            event.where = "WHERE " + id + "=" + num + " ";
        }
        else
        {
            event.where += event.and_ + id + "=" + num + " ";
        }        
        event.w_call++;
        return *this;
    }
   
private:
    Query event;
};



void Printquery(const Query& e)
{
    for (const auto& query : e.query_V)
    {
        std::cout << query;
    }   

}

int main() {

    QueryBuilder a;
       a.AddColumn("1wert, 2ropu")
        .AddFrom("cok")
        .AddWhere("id", "50")
        .AddWhere("name", "John");
    Printquery(a.Buildquery());

    std::cout << std::endl;

    QueryBuilder b;
    /*b.AddFrom("ERT")
        .AddWhere("id", "90")
        .AddWhere("name", "Karl");*/
    Printquery(b.Buildquery());
        
}
