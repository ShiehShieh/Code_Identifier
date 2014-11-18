from django.conf.urls import include, url
from django.contrib import admin
from mysite.views import hello, root, serverTime, plusTime, body
from books.views import search
from contact.views import contact_form, contact_thanks

admin.autodiscover()

urlpatterns = [
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r"^hello/$", hello),
    url(r"^$", root),
    url(r"^servertime/$", serverTime),
    url(r"^time/plus/(\d{1,2})/$", plusTime),
    url(r"^body/$", body),
    url(r"^search/$", search),
    url(r"^contact/$", contact_form),
    url(r"^contact/thanks/$", contact_thanks)
]
