from inspect import getfullargspec

class LazyInit(type):

    def __new__(meta, class_name, supers, class_dict):
        class_dict['__init__'] = LazyInitDecorator(class_dict['__init__'])
        return type.__new__(meta, class_name, supers, class_dict)

def LazyInitDecorator(to_decore):

    def wrapper(*args):
        args_names = getfullargspec(to_decore)[0]

        args_values = [x for x in args[1:]]

        obj_ref = args[0]

        for x in args_names[1:]:
     	    obj_ref.__setattr__(x, args_values.pop(0))
    
    return wrapper
