class CustomInt(int):
    def __call__(self, v):
        return CustomInt(self + v)

def add(v):
    return CustomInt(v)
