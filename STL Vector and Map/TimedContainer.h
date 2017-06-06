#ifndef TIMEDCONTAINER_H_
#define TIMEDCONTAINER_H_

class TimedContainer
{
public:
    TimedContainer();
    virtual ~TimedContainer();

    void reset_elapsed_time();
    long get_elapsed_time() const;

protected:
    void increment_elapsed_time(const long usec);

private:
    long elapsed_time;
};

#endif /* TIMEDCONTAINER_H_ */
