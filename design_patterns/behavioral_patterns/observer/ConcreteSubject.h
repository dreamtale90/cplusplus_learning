#if !defined(EA_61998456_1B61_49f4_B2EA_9D28EEBC9649__INCLUDED_)
#define EA_61998456_1B61_49f4_B2EA_9D28EEBC9649__INCLUDED_

#include "Subject.h"

class ConcreteSubject : public Subject
{

    public:
        ConcreteSubject();
        virtual ~ConcreteSubject();

        virtual int getState();
        virtual void setState(int i);

    private:
        int m_state;

};
#endif // !defined(EA_61998456_1B61_49f4_B3EA_9D28EEBC9649__INCLUDED_)
