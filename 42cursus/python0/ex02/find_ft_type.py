def all_thing_is_obj(object: any) -> int:
    object_cls = object.__class__
    if object_cls == int:
        print("Type not found")
    elif object_cls == str:
        print(f"{object} is in the kitchen : {object_cls}")
    else:
        print(f"{object_cls.__name__.capitalize()} : {object_cls}")
    return 42
