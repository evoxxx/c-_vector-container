namespace container
{
	template<class N>

	struct 
		vector
	{
	private:
		N* v;
		size_t s;
	public:
		vector() {
			v = new N[this->s = 0];
		}
		~vector() {
			delete[]v;
		}
		size_t length() {
			return this->s;
		}
		void push_back(const N& value) {
			N* v2 = new N[++s];
			for (size_t i = 0; i < s - 1; i++)
				v2[i] = v[i];
			v2[s-1] = value;
			v = new N[s];
			v = v2;
		}
		const N& pop_back() {
			assert(this->s >= 1);
			N last = v[this->s-1];
			N* v2 = new N[s];
			v2 = v;
			N* v = new N[--s];
			for (unsigned int i = 0; i < s; i++)
				v[i] = v2[i];
			return last;
		}
		const N& get(const N& index) {
			return v[index];
		}
		const N& operator [](size_t index) {
			assert(index < this->s);
			return this->v[index];
		}
		int find(const N& value) {
			for (size_t i = 0; i < this->s; i++) {
				if (v[i] == value)
					return i;
			}
			return -1;
		}
		bool empty() const {
			return this->s == 0;
		}
		void resize(const size_t & size) {
			assert(this->s != size);
			N * new_vec = v;
			v = new N[size];
			if (size > s)
			{
				for (size_t i = 0; i < s; i++)
					v[i] = new_vec[i];
				for (size_t i = s; i < size; i++)
					v[i] = 0;
			}
			else
			{
				for (size_t i = 0; i < size; i++)
					v[i] = new_vec[i];
			}

			this->s = size;
		}
	};
}
