from django.shortcuts import render

# Create your views here.

from django.conf import settings


import rest_framework
from rest_framework import  viewsets


from .models import Supercar
from .serializers import SupercarSerializer


class SupercarViewSet(viewsets.ModelViewSet):
    queryset = Supercar.objects.all()
    serializer_class = SupercarSerializer
