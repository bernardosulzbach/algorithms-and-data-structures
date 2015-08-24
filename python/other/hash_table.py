from shash import shash


class HashTable():
    """
    My implementation of a hash table.
    """
    def __init__(self, bucket_count=50):
        """
        Creates a new HashTable.
        :param bucket_count: the amount of buckets to start with (must be positive)
        :return: an empty HashTable
        """
        assert bucket_count > 0, 'Buckets should be positive.'
        self.length = 0
        self.bucket_count = bucket_count
        self.buckets = [[] for i in range(bucket_count)]

    def __contains__(self, key):
        return self.get(key) is not None

    def __len__(self):
        return self.length

    def _get_bucket(self, key):
        """
        Hashes a key string and returns the corresponding bucket.
        :param key: a key string
        :return: a bucket (list)
        """
        return self.buckets[shash(key) % self.bucket_count]

    def insert(self, key, content):
        """
        Inserts an object into the HashTable.
        :param key: the key
        :param content: the object
        :return: True if successful, False otherwise
        """
        if key not in self:
            self._get_bucket(key).append((key, content))
            self.length += 1
            return True
        return False

    def erase(self, key):
        """
        Erases the object referred to by a key string.
        :param key: the key
        :return: True if successful, False otherwise
        """
        if key in self:
            self._get_bucket(key).remove((key, self.get(key)))
            self.length -= 1
            return True
        return False

    def get(self, key):
        """
        Retrieves the element pointed to by a key string.
        :param key: the key
        :return: an object or None
        """
        bucket = self._get_bucket(key)
        for pair in bucket:
            if pair[0] == key:
                return pair[1]
        return None


if __name__ == '__main__':
    ht = HashTable()
    ht.insert('jesus', 'christ')
    print(ht.get('jesus'))
    ht.erase('jesus')
    print(ht.get('jesus'))
    ht.insert('jesus', 'omnipresent')
    print(ht.get('jesus'))
    ht.insert('mohamed', 'christ')
    print('Length =', len(ht), "(should be 2)")
