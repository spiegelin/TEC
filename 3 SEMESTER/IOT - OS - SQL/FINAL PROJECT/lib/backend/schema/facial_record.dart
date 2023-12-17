import 'dart:async';

import 'package:collection/collection.dart';

import '/backend/schema/util/firestore_util.dart';
import '/backend/schema/util/schema_util.dart';

import 'index.dart';
import '/flutter_flow/flutter_flow_util.dart';

class FacialRecord extends FirestoreRecord {
  FacialRecord._(
    DocumentReference reference,
    Map<String, dynamic> data,
  ) : super(reference, data) {
    _initializeFields();
  }

  // "lastAccess" field.
  DateTime? _lastAccess;
  DateTime? get lastAccess => _lastAccess;
  bool hasLastAccess() => _lastAccess != null;

  // "name" field.
  String? _name;
  String get name => _name ?? '';
  bool hasName() => _name != null;

  void _initializeFields() {
    _lastAccess = snapshotData['lastAccess'] as DateTime?;
    _name = snapshotData['name'] as String?;
  }

  static CollectionReference get collection =>
      FirebaseFirestore.instance.collection('facial');

  static Stream<FacialRecord> getDocument(DocumentReference ref) =>
      ref.snapshots().map((s) => FacialRecord.fromSnapshot(s));

  static Future<FacialRecord> getDocumentOnce(DocumentReference ref) =>
      ref.get().then((s) => FacialRecord.fromSnapshot(s));

  static FacialRecord fromSnapshot(DocumentSnapshot snapshot) => FacialRecord._(
        snapshot.reference,
        mapFromFirestore(snapshot.data() as Map<String, dynamic>),
      );

  static FacialRecord getDocumentFromData(
    Map<String, dynamic> data,
    DocumentReference reference,
  ) =>
      FacialRecord._(reference, mapFromFirestore(data));

  @override
  String toString() =>
      'FacialRecord(reference: ${reference.path}, data: $snapshotData)';

  @override
  int get hashCode => reference.path.hashCode;

  @override
  bool operator ==(other) =>
      other is FacialRecord &&
      reference.path.hashCode == other.reference.path.hashCode;
}

Map<String, dynamic> createFacialRecordData({
  DateTime? lastAccess,
  String? name,
}) {
  final firestoreData = mapToFirestore(
    <String, dynamic>{
      'lastAccess': lastAccess,
      'name': name,
    }.withoutNulls,
  );

  return firestoreData;
}

class FacialRecordDocumentEquality implements Equality<FacialRecord> {
  const FacialRecordDocumentEquality();

  @override
  bool equals(FacialRecord? e1, FacialRecord? e2) {
    return e1?.lastAccess == e2?.lastAccess && e1?.name == e2?.name;
  }

  @override
  int hash(FacialRecord? e) =>
      const ListEquality().hash([e?.lastAccess, e?.name]);

  @override
  bool isValidKey(Object? o) => o is FacialRecord;
}
