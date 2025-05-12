from rest_framework import serializers


from .models import Supercar


class SupercarSerializer(serializers.ModelSerializer):
   
    class Meta:
        model = Supercar
        fields = '__all__'