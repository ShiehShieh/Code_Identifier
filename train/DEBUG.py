from books.models import Publisher

def debug():
	p1 = Publisher.objects.create(name='Apress',address='2855 Telegraph Avenue',city='Berkeley', state_province='CA', country='U.S.A.',website='http://www.apress.com/')
	p1.save()
	publisher_list = Publisher.objects.all()
	print publisher_list