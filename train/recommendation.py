

FILENAME = 'restaurants_small.txt'


def recommend(file, price, cuisines_list):


    name_to_rating, price_to_names, cuisine_to_names = read_restaurants(file)


    names_matching_price = price_to_names[price]

    names_final = filter_by_cuisine(names_matching_price, cuisine_to_names, cuisines_list)

    result = build_rating_list(name_to_rating, names_final)

    return result

def build_rating_list(name_to_rating, names_final):
    pass


def filter_by_cuisine(names_matching_price, cuisine_to_names, cuisines_list):
    pass

def read_restaurants(file):


    name_to_rating = {}
    price_to_names = {'$': [], '$$': [], '$$$': [], '$$$$': []}
    cuisine_to_names = {}
