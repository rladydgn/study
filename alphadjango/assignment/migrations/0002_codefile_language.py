# Generated by Django 4.0.3 on 2022-07-10 08:43

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('assignment', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='codefile',
            name='language',
            field=models.CharField(default='python', max_length=50),
        ),
    ]
