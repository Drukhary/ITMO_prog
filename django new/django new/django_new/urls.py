"""
Definition of urls for django_new.
"""

#from datetime import datetime
from django.urls import path
from django.contrib import admin
#from django.contrib.auth.views import LoginView, LogoutView
#from app import forms, views
from django_new import views


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index, name='index'),
    path('hello', views.indexRender, name='indexRender'),
    path('ITMO', views.ITMO_University, name='ITMO'),
    path('discipline', views.disc, name='discipline'),
    path('group', views.group, name='group'),
    path('departaments', views.deps, name='departaments'),
    path('structureITMO', views.ITMO_structure, name='ITMOstructure')
    
]
