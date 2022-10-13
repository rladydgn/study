from django.urls import path, include
from rest_framework import routers

from posts.views import PostViewSet, likes

router = routers.SimpleRouter()
router.register('view/posts', PostViewSet)

urlpatterns = router.urls + [
    path('likes/<int:pk>/', likes, name='likes')
]
# urlpatterns = router.urls + [
#     path('posts/', include('posts.urls'))
# ]
# 미디어 파일 경로 추가
