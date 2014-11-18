input_str = raw_input()
input_str = input_str[:input_str.index('#')]
exp_f,exp_s = input_str.split('=')

def exf_i(ex,ei,eto,eresult,ef): 
	ec = ex.count(ei)
	if ec < 1: return True
	exp_i = 0
	for i in range(ec):
		exp_i = ex.index(ei,exp_i)
		exp_clone = ex[:exp_i] + eto + ex[exp_i + 1:]
		if eval(exp_clone) == eval(eresult):
			if ef:
				print(exp_clone + '=' + eresult + '#')
			else:
				print(eresult + '=' + exp_clone + '#')
			return False
	return True

def estr(ex,ef,eto):
	return ex[:ef] + ex[eto] + ex[ef+1:eto] + ex[ef] + ex[eto + 1:]

def ecf_c(ex,ei,eto,eresult,ef):
	ec = min(ex.count(ei),ex.count(eto))
	if ec < 1: return True
	exp_i = 0
	exp_t = 0
	for i in range(ec):
		exp_i = ex.index(ei,exp_i + 1)
		exp_t = ex.index(eto,exp_t + 1)
		exp_clone = estr(ex,exp_i,exp_t)
		if eval(exp_clone) == eval(eresult):
			if ef:
				print(exp_clone + '=' + eresult + '#')
			else:
				print(eresult + '=' + exp_clone + '#')
			return False
	return True

if exf_i(exp_f,'2','3',exp_s,True):
	if exf_i(exp_f,'3','2',exp_s,True):
		if exf_i(exp_f,'3','5',exp_s,True):
			if exf_i(exp_f,'5','2',exp_s,True):
				if exf_i(exp_f,'6','9',exp_s,True):
					if exf_i(exp_s,'2','3',exp_f,False):
						if exf_i(exp_s,'3','2',exp_f,False):
							if exf_i(exp_s,'3','5',exp_f,False):
								if exf_i(exp_s,'5','2',exp_f,False):
									if exf_i(exp_s,'6','9',exp_f,False):
										if ecf_c(exp_f,'1','7',exp_s,True):
											if ecf_c(exp_s,'1','7',exp_f,False):
												print('No')
