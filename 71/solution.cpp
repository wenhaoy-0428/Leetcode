#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path)
{
    stack<string> pathStack;

    size_t pos = 0;
    while (pos < path.length())
    {
        size_t prev = pos;
        pos = path.find('/', pos + 1);
        if (pos == string::npos)
        {
            pos = path.length();
        }

        string fileName = path.substr(prev + 1, pos - prev - 1);
        cout << "file name: " << fileName.length() << ":" << fileName << endl;
        if (fileName.empty() || fileName == ".")
        {
            continue;
        }
        if (fileName == "..")
        {
            if (!pathStack.empty())
            {
                pathStack.pop();
            }
            continue;
        }

        pathStack.push(fileName);
    }

    string result = "";

    while (!pathStack.empty())
    {
        cout << pathStack.top() << endl;
        result.insert(0, "/" + pathStack.top());
        pathStack.pop();
    }

    if (result.empty())
    {
        result = "/";
    }

    return result;
}

int main()
{
    cout << simplifyPath("/home/../foo/") << endl;
}
