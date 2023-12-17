import 'dart:async';

import 'package:collection/collection.dart';

import '/backend/schema/util/firestore_util.dart';
import '/backend/schema/util/schema_util.dart';

import 'index.dart';
import '/flutter_flow/flutter_flow_util.dart';

class LockRecord extends FirestoreRecord {
  LockRecord._(
    DocumentReference reference,
    Map<String, dynamic> data,
  ) : super(reference, data) {
    _initializeFields();
  }

  // "carga" field.
  String? _carga;
  String get carga => _carga ?? '';
  bool hasCarga() => _carga != null;

  // "open" field.
  bool? _open;
  bool get open => _open ?? false;
  bool hasOpen() => _open != null;

  void _initializeFields() {
    _carga = snapshotData['carga'] as String?;
    _open = snapshotData['open'] as bool?;
  }

  static CollectionReference get collection =>
      FirebaseFirestore.instance.collection('lock');

  static Stream<LockRecord> getDocument(DocumentReference ref) =>
      ref.snapshots().map((s) => LockRecord.fromSnapshot(s));

  static Future<LockRecord> getDocumentOnce(DocumentReference ref) =>
      ref.get().then((s) => LockRecord.fromSnapshot(s));

  static LockRecord fromSnapshot(DocumentSnapshot snapshot) => LockRecord._(
        snapshot.reference,
        mapFromFirestore(snapshot.data() as Map<String, dynamic>),
      );

  static LockRecord getDocumentFromData(
    Map<String, dynamic> data,
    DocumentReference reference,
  ) =>
      LockRecord._(reference, mapFromFirestore(data));

  @override
  String toString() =>
      'LockRecord(reference: ${reference.path}, data: $snapshotData)';

  @override
  int get hashCode => reference.path.hashCode;

  @override
  bool operator ==(other) =>
      other is LockRecord &&
      reference.path.hashCode == other.reference.path.hashCode;
}

Map<String, dynamic> createLockRecordData({
  String? carga,
  bool? open,
}) {
  final firestoreData = mapToFirestore(
    <String, dynamic>{
      'carga': carga,
      'open': open,
    }.withoutNulls,
  );

  return firestoreData;
}

class LockRecordDocumentEquality implements Equality<LockRecord> {
  const LockRecordDocumentEquality();

  @override
  bool equals(LockRecord? e1, LockRecord? e2) {
    return e1?.carga == e2?.carga && e1?.open == e2?.open;
  }

  @override
  int hash(LockRecord? e) => const ListEquality().hash([e?.carga, e?.open]);

  @override
  bool isValidKey(Object? o) => o is LockRecord;
}
