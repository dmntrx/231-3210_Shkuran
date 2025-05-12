from django.db import models

# Create your models here.

class Supercar(models.Model):
    car_brand = models.CharField(max_length=30, null=True)
    car_model = models.CharField(max_length=30, null=True)
    brand_country = models.CharField(max_length=30, null=True)
    release_date = models.DateField(null=True)
    max_speed = models.IntegerField(null=True)
    engine_name = models.CharField(max_length=30, null=True)

    # random.integer и тд  
    # дефолтный порт на постгрес оставить, пользователь postgres, пароль postgres