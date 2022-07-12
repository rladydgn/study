from django.db import models

# from assignment.models import CodeFile


class CodeFile(models.Model):
    path = models.CharField(max_length=256, primary_key=True)
    published_date = models.DateTimeField(auto_now_add=True)
    code = models.TextField()
    language = models.CharField(max_length=50, default='python')

    def __str__(self):
        return self.published_date
