import random, string, datetime
from .models import *
from django.db import transaction
import faker
from faker import Faker

fk = Faker()

def gentestdata():

    with transaction.atomic():
        for _ in range(1000):
            new_supercar = Supercar()
            new_supercar.car_brand = random.choice(['Ferrari', 'Lamborghini', 'Aston Martin', 'McLaren', 'Porsche'])
            new_supercar.car_model = random.choice(['F8 Tributo', 'Sian', 'DBS', '720S', '911 Turbo'])
            new_supercar.brand_country = random.choice(['Italy', 'Germany', 'UK', 'France'])
            new_supercar.release_date = datetime.date(random.randint(1990, 2025), 1, 1)
            new_supercar.max_speed = random.randint(250, 450)
            new_supercar.engine_name = random.choice(['V8', 'V10', 'V12', 'Inline-6', 'Hybrid'])
            new_supercar.save()
    print('OK gentestdata()')
