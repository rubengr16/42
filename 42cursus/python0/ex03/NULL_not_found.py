from math import isnan


def NULL_not_found(object: any) -> int:
	header_dict = {
		float: "Cheese",
		int: "Zero",
		str: "Empty",
		bool: "Fake"
	}
	if object and not (isinstance(object, float) and isnan(float("NaN"))):
		print("Type not Found")
		return 1
	object_cls = object.__class__
	print(f"{header_dict.get(object_cls, "Nothing")}: {object} {object_cls}")
	return 0
