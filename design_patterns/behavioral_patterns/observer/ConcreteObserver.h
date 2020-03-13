#if !defined(EA_7B020534_BFEA_4c9e_8E4C_34DCE001E9B1__INCLUDED_)
#define EA_7B020534_BFEA_4c9e_8E4C_34DCE001E9B1__INCLUDED_
#include "Observer.h"
#include <string>
using namespace std;

class ConcreteObserver : public Observer
{

    public:
        ConcreteObserver(string name);
        virtual ~ConcreteObserver();
        virtual void update(Subject * sub);

    private:
        string m_objName;
        int m_obeserverState;
};
#endif // !defined(EA_7B020534_BFEA_4c9e_8E4C_34DCE001E9B1__INCLUDED_)
