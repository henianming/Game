#ifndef SINGLETONTEMPLATE
#define SINGLETONTEMPLATE

template<typename T>
class SingletonTemplate {
private:
	static T* m_singleton;

public:
	static T* GetInstance() {
		if (!m_singleton) {
			m_singleton = new T();
		}
		return m_singleton;
	}

protected:
	SingletonTemplate() {
	}
};

#endif //SINGLETONTEMPLATE