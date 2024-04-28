import CToolKit as ct

STARTER  = f'src/one.h'
OUTPUT = 'decklib.h'
amalgamated_code = ct.generate_amalgamated_code(STARTER,OUTPUT)