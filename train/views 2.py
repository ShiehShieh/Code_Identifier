from django.http import HttpResponse, Http404
from django.template import Template, Context
from django.template.loader import get_template
import time
import datetime

def hello(request):
	return HttpResponse("Hello world.")

def root(request):
	return HttpResponse("You are in the root.")

def serverTime(request):
	serverTimes = time.ctime()
	html = "" %(serverTimes)
	return HttpResponse(html)

def plusTime(request, offSet):
	try:
		plusTimes = int(offSet)
	except ValueError:
		raise Http404
	currentTime = datetime.datetime.now() + datetime.timedelta(hours = plusTimes)
	html = "" %(currentTime)
	return HttpResponse(html)

def body(request):
	t = get_template("body.html")
	c = Context({"none" : "nothing"})
	html = t.render(c)
	return HttpResponse(html)
