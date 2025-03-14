[[nodiscard]] inline
struct slink* slist_front( struct slist *list ) {
  return list->head != nullptr ? list->head : nullptr;
}

[[nodiscard]] inline
struct slink* slist_back( struct slist *list ) {
  return list->tail != nullptr ? list->tail : nullptr;
}

[[nodiscard]] inline
bool slist_empty( struct slist *list ) {
  return list->head == nullptr;
}
