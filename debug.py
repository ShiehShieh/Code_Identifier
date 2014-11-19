#!/usr/bin/env python
# coding=utf-8
#        debug decorator which trigger pdb when exception raised
#        C19<classone2010@gmail.com>

import pdb, traceback, sys
from pprint import PrettyPrinter

pprint = PrettyPrinter(indent=4).pprint

def debug(func):
	def wrap(*arg, **kwarg):
		try:
			return func(*arg, **kwarg)
		except:
			type, value, tb = sys.exc_info()
			traceback.print_exc()
			pdb.post_mortem(tb)
	return wrap